/* 
HexadecimalColorMixer.cpp : Given an array of strings colors containing a series of hexadecimal codes, 
                            implement a function that returns the hexadecimal code of the new color, as a new string.
*/

#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <algorithm>

int RGBcolor(std::string hexResult)
{
    std::stringstream ss;
    int x;
    ss << std::hex << hexResult;
    ss >> x;

    return x;
}

std::string HEXcolor(int rgb)
{
    std::stringstream ss;
    ss << std::hex << rgb;
    std::string result(ss.str());
   
    return result;
}

std::string hexColorMixer(std::vector<std::string> colors) 
{
    std::vector<int> oldRGB;
   
    int newRGB[3] = { 0, 0, 0 };
    std::string hexResult;
   // std::string resultRGB[3];
    std::string result;
    for (int i = 0; i < colors.size(); i++)
    {
        for (int j = 0; j < 6; j += 2)
        {
            hexResult += colors[i][j];
            hexResult += colors[i][j + 1];
            oldRGB.push_back(RGBcolor(hexResult));
            hexResult = "";
        }

    }

    for (int i = 0; i < oldRGB.size(); i +=3)
    {
        newRGB[0] += oldRGB[i];
        newRGB[1] += oldRGB[i+1];
        newRGB[2] += oldRGB[i+2];
    }

    for (int i = 0; i < 3; i++)
    {   
        newRGB[i] = round(newRGB[i] / colors.size());
        if (newRGB[i] > 0 && newRGB[i] <= 9)
        {
            result += HEXcolor(newRGB[i] + 1);
            result += "0";
        }
        else if(newRGB[i] == 0)
            result += "00";
        else
            result += HEXcolor(newRGB[i] + 1);
    }

    std::transform(result.begin(), result.end(), result.begin(), ::toupper);
    return result;
}

int main()
{
    std::string color;
    std::vector<std::string> colors;

    std::cout << "Enter code of colors to mix (Enter 'End' to stop): \n";

    while (true)
    {
        std::cout << "#";
        std::cin >> color;
        if (color == "End")
            break;
        colors.push_back(color);
    }
    std::cout << "Resulting color is: #" << hexColorMixer(colors);
}

