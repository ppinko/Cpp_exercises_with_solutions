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
    record.Tgntot = atof(line[4U].c_str());
    record.TgntotStdDev = atof(line[5U].c_str());
    record.Tgetot = atof(line[6U].c_str());
    record.TgetotStdDev = atof(line[7U].c_str());
    return record;
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