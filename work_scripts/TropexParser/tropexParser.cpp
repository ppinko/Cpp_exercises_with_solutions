#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cctype>
#include <cstdint>
#include <cstdlib>

/// <summary>
/// Struct holding values of a single record describing troposphere conditions.
/// </summary>
struct TropoRecord
{
public:
    /// <summary>
    /// Epoch.
    /// </summary>
    std::string Epoch{};

    /// <summary>
    /// Total zenith path delay [mm]
    /// </summary>
    double Trotot{};

    /// <summary>
    /// Standard deviation of total zenith path delay.
    /// </summary>
    double TrototStdDev{};

    /// <summary>
    /// Total troposphere gradient in north (wet + dry part) [m].
    /// </summary>
    double Tgntot{};

    /// <summary>
    /// Standard deviation of total troposphere gradient in north (wet + dry).
    /// </summary>
    double TgntotStdDev{};

    /// <summary>
    /// Total troposphere gradient in east (wet + dry
    /// </summary>
    double Tgetot{};

    /// <summary>
    /// Standard deviation of total troposphere gradient in north (wet + dry).
    /// </summary>
    double TgetotStdDev{};
};

std::vector<std::string> SplitLines(const std::string &line)
{
    std::vector<std::string> result{};
    std::string word{};
    for (auto const &ch : line)
    {
        if (!std::isspace(ch))
        {
            word += ch;
        }
        else if (!word.empty())
        {
            result.push_back(word);
            word.clear();
        }
    }
    if (!word.empty())
    {
        result.push_back(word);
    }
    return result;
}

TropoRecord ParseRecord(const std::vector<std::string> &line)
{
    TropoRecord record{};
    record.Epoch = line[1U];
    record.Trotot = std::atof(line[2U].c_str());
    record.TrototStdDev = std::atof(line[3U].c_str());
    record.Tgntot = std::atof(line[4U].c_str());
    record.TgntotStdDev = std::atof(line[5U].c_str());
    record.Tgetot = std::atof(line[6U].c_str());
    record.TgetotStdDev = std::atof(line[7U].c_str());
    return record;
}

void ParseStationCoordinates(std::fstream &file)
{
    size_t section{0U};
    char c{};
    std::string currentLine{};
    while (file.get(c))
    {
        if (c != '\n')
        {
            currentLine += c;
        }
        else
        {
            if (section == 0U)
            {
                if (currentLine != "*SITE PT SOLN T __STA_X_____ __STA_Y_____ __STA_Z_____ SYSTEM REMRK")
                {
                    throw("Wrong station coordinates header");
                }
                ++section;
                currentLine.clear();
            }
            else if (section == 1U)
            {
                auto line = SplitLines(currentLine);
                if (line.size() != 9U)
                {
                    throw("Wrong number of elements in station coordinates.");
                }
                auto const posX = atof(line[4U].c_str());
                auto const posY = atof(line[5U].c_str());
                auto const posZ = atof(line[6U].c_str());
                (void)posX;
                (void)posY;
                (void)posZ;
                // create ECEF position of the stations
                ++section;
            }
            else if (section == 2U)
            {
                if (currentLine == "-TROP/STA_COORDINATES")
                {
                    return;
                }
                else
                {
                    throw("Station coordinates section not closed properly.");
                }
            }
            else
            {
                throw("Station coordinates section have too many lines.");
            }
        }
    }
    throw("Reached end of the file without closing station coordinates section.");
}

void ParseSolution(std::vector<TropoRecord> &records,
                   std::fstream &file)
{
    size_t section{0U};
    char c{};
    std::string currentLine{};
    while (file.get(c))
    {
        if (c != '\n')
        {
            currentLine += c;
        }
        else
        {
            if (section == 0U)
            {
                if (currentLine != "*SITE ____EPOCH___ TROTOT STDDEV  TGNTOT STDDEV  TGETOT STDDEV")
                {
                    throw("Wrong solution header");
                }
                ++section;
                currentLine.clear();
            }
            else if (currentLine == "-TROP/SOLUTION")
            {
                return;
            }
            else
            {
                auto line = SplitLines(currentLine);
                if (line.size() != 8U)
                {
                    throw("Wrong number of elements in a single record.");
                }
                records.push_back(ParseRecord(line));
                currentLine.clear();
            }
        }
    }
    throw("Reached end of the file without closing solution part.");
}

void ParseDescription(std::fstream &file)
{
    size_t section{0U};
    char c{};
    std::string currentLine{};
    while (file.get(c))
    {
        if (c != '\n')
        {
            currentLine += c;
        }
        else
        {
            if (section == 0U)
            {
                if (currentLine == " ELEVATION CUTOFF ANGLE")
                {
                    auto const line = SplitLines(currentLine);
                    auto const _elevationCutoffAngle = std::atoi(line.back().c_str());
                    ++section;
                }
                currentLine.clear();
            }
            else if (section == 1U)
            {
                if (currentLine == " SAMPLING INTERVAL")
                {
                    auto const line = SplitLines(currentLine);
                    auto const _samplingInterval = std::atoi(line.back().c_str());
                    ++section;
                }
                else
                {
                    throw("Sampling interval not found after elevation cutoff angle.");
                }
                currentLine.clear();
            }
            else if (section == 2U)
            {
                if (currentLine == " TROP MAPPING FUNCTION")
                {
                    auto const line = SplitLines(currentLine);
                    std::string _mappingFunction{};
                    for (size_t i{3U}; i < line.size(); ++i)
                    {
                        _mappingFunction += line[i];
                        if (i != line.size() - 1U)
                        {
                            _mappingFunction += ' ';
                        }
                    }
                    ++section;
                }
                currentLine.clear();
            }
            else if (section == 3U)
            {
                if (currentLine != " SOLUTION_FIELDS_1             TROTOT STDDEV TGNTOT STDDEV TGETOT STDDEV")
                {
                    throw("Solution fields contain unexpected values.");
                }
                ++section;
                currentLine.clear();
            }
            else if ((section == 4U) && (currentLine == "-TROP/DESCRIPTION"))
            {
                return;
            }
            else
            {
                throw("Description coordinates section not closed properly.");
            }
        }
    }
    throw("Reached end of the file without closing description section.");
}

int main()
{
    int i{10};
    std::cout << "Hello" << std::endl;
    std::vector<TropoRecord> records{};
    std::fstream file{"tropSolution.txt", std::ios::in};
    ParseSolution(records, file);
    ++i;
    records.empty();
}