#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <iomanip>
#include <vector>
#include <tuple>

using Point = std::tuple<double, double, double, int, int, int>;

// 检查文件末尾是否已有换行符
bool fileEndsWithNewline(const std::string& filename) {
    std::ifstream f(filename, std::ios::binary);
    if (!f.is_open()) return true;
    f.seekg(0, std::ios::end);
    std::streampos size = f.tellg();
    if (size == 0) return true;  // 空文件认为已有换行（无影响）
    f.seekg(-1, std::ios::end);
    char ch;
    f.get(ch);
    return ch == '\n';
}

void processPoints() {
    const std::string inputFile = "points.csv";
    const std::string offsetFile = "points_offset.csv";

    std::ifstream fin(inputFile);
    if (!fin.is_open()) return;

    // 读取文件头
    std::string header;
    std::getline(fin, header);

    // 存储所有点云数据
    std::vector<Point> points;
    double sumX = 0.0, sumY = 0.0, sumZ = 0.0;
    int count = 0;
    std::string line;

    while (std::getline(fin, line)) {
        if (line.empty()) continue;
        std::stringstream ss(line);
        std::string token;

        double x, y, z;
        int r, g, b;

        std::getline(ss, token, ','); x = std::stod(token);
        std::getline(ss, token, ','); y = std::stod(token);
        std::getline(ss, token, ','); z = std::stod(token);
        std::getline(ss, token, ','); r = std::stoi(token);
        std::getline(ss, token, ','); g = std::stoi(token);
        std::getline(ss, token, ','); b = std::stoi(token);

        points.emplace_back(x, y, z, r, g, b);
        sumX += x;
        sumY += y;
        sumZ += z;
        ++count;
    }
    fin.close();

    if (count == 0) return;

    // 计算重心坐标
    double cx = sumX / count;
    double cy = sumY / count;
    double cz = sumZ / count;

    // 将重心追加到 points.csv 末尾
    std::ofstream fout(inputFile, std::ios::app);
    if (fout.is_open()) {
        // 确保末尾有换行符，避免数据粘连
        if (!fileEndsWithNewline(inputFile)) {
            fout << std::endl;
        }
        fout << std::fixed << std::setprecision(3);
        fout << cx << "," << cy << "," << cz << ",0,0,0" << std::endl;
        fout.close();
    }

    // 生成偏移后的点云文件 points_offset.csv
    std::ofstream fout2(offsetFile);
    if (!fout2.is_open()) return;

    fout2 << header << std::endl;
    fout2 << std::fixed << std::setprecision(3);
    for (const auto& p : points) {
        double x = std::get<0>(p) + 100.0;
        double y = std::get<1>(p) + 50.0;
        double z = std::get<2>(p);
        int r = std::get<3>(p);
        int g = std::get<4>(p);
        int b = std::get<5>(p);
        fout2 << x << "," << y << "," << z << ","
              << r << "," << g << "," << b << std::endl;
    }
    fout2.close();
}