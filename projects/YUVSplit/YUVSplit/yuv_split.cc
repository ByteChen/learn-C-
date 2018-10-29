/*
* Author: ByteChen@qq.com
* Date: 2018/5/29
* Usage: 将YUV文件分割成42个tile，并生成一个脚本文件，运行脚本文件会将YUV tile采样到相同分辨率。
*/

#include<iostream>
#include<string>
#include<vector>

using std::string;
using std::to_string;

int main(int argc, char* argv[]) {
    if (argc != 4) {
        std::cerr << "error input!\nstandard input: YUVfileName, pixelWidth, pixelHeight\n";
        std::cerr << "Usage: 将YUV文件分割成42个tile，并生成一个脚本文件，运行脚本文件会将YUV tile采样到相同分辨率。\n";
        std::cerr << "建议输入的YUV文件名形如 Harbor_7680x3840.yuv，这样输出的文件名更佳\n";
        system("pause");
        return -1;
    }
    FILE* fpInFile;
    char* input_path = argv[1];
    fpInFile = fopen(input_path, "rb");
    int pixelWidth = atoi(argv[2]);
    int pixelHeight = atoi(argv[3]);
    //int size = pixelWidth*pixelHeight * 3 / 2;
    unsigned long long size = unsigned long long(pixelWidth)*unsigned long long(pixelHeight) * 3 / 2;
    uint8_t* buf = new uint8_t[size];  // 存储原始YUV帧的buffer
    uint8_t* tmp_buffer = new uint8_t[size / 6 / 3];    // 最大能装第一行的tile

    // 构造输出文件名数组
    string basename(argv[1]);
    basename = basename.substr(0, basename.size() - 13);
    string outputfilename[42];
    FILE* fp[42];
    std::vector<bool> isfirsttimeopenfile(42, true);
    // 生成batch脚本名字
    string scriptfilename = basename.substr(0, basename.find_last_of('\\') + 1);    // 从YUV路径中提取所在的目录，作为输出目录
    scriptfilename += "script.bat";
    FILE* scriptfile = fopen(scriptfilename.c_str(), "wb");

    int start_y, start_uv, copyWidth;
    while (fread(buf, 1, size, fpInFile)) {
        for (int index = 0; index < 42; index++) {
            if (index <= 2) {
                copyWidth = pixelWidth / 3;
                start_y = index*copyWidth;       // start_y是当前tile的Y分量的相对起始地址
                start_uv = index*copyWidth / 2;  // start_uv是当前tile的U、V分量的相对起始地址
                outputfilename[index] = basename + std::to_string(copyWidth) + "x" +
                    std::to_string(pixelHeight / 6) + "_" + std::to_string(index) + ".yuv";
            } else if (index >2 && index <= 8) {
                copyWidth = pixelWidth / 6;
                start_y = pixelHeight*pixelWidth / 6 + (index - 3)*copyWidth;
                start_uv = pixelHeight*pixelWidth / 24 + (index - 3)*copyWidth / 2;
                outputfilename[index] = basename + std::to_string(copyWidth) + "x" +
                    std::to_string(pixelHeight / 6) + "_" + std::to_string(index) + ".yuv";
            } else if (index >8 && index <= 20) {
                copyWidth = pixelWidth / 12;
                start_y = pixelHeight*pixelWidth / 3 + (index - 9)*copyWidth;
                start_uv = pixelHeight*pixelWidth / 12 + (index - 9)*copyWidth / 2;
                outputfilename[index] = basename + std::to_string(copyWidth) + "x" +
                    std::to_string(pixelHeight / 6) + "_" + std::to_string(index) + ".yuv";
            } else if (index >20 && index <= 32) {
                copyWidth = pixelWidth / 12;
                start_y = pixelHeight*pixelWidth / 2 + (index - 21)*copyWidth;
                start_uv = pixelHeight*pixelWidth / 8 + (index - 21)*copyWidth / 2;
                outputfilename[index] = basename + std::to_string(copyWidth) + "x" +
                    std::to_string(pixelHeight / 6) + "_" + std::to_string(index) + ".yuv";
            } else if (index >32 && index <= 38) {
                copyWidth = pixelWidth / 6;
                start_y = pixelHeight*pixelWidth / 6 * 4 + (index - 33)*copyWidth;
                start_uv = pixelHeight*pixelWidth / 6 + (index - 33)*copyWidth / 2;
                outputfilename[index] = basename + std::to_string(copyWidth) + "x" +
                    std::to_string(pixelHeight / 6) + "_" + std::to_string(index) + ".yuv";
            } else {
                copyWidth = pixelWidth / 3;
                start_y = pixelHeight*pixelWidth / 6 * 5 + (index - 39)*copyWidth;
                start_uv = pixelHeight*pixelWidth / 24 * 5 + (index - 39)*copyWidth / 2;
                outputfilename[index] = basename + std::to_string(copyWidth) + "x" +
                    std::to_string(pixelHeight / 6) + "_" + std::to_string(index) + ".yuv";
            }

            //copy Y 分量
            uint8_t *p = tmp_buffer;
            for (int i = 0; i< pixelHeight / 6; i++) {
                memcpy(p, buf + start_y + i*pixelWidth, copyWidth);
                p += copyWidth;
            }

            //copy U 分量
            static uint8_t* offset_U = buf + pixelWidth*pixelHeight;
            int copyWidth_UV = copyWidth / 2;
            for (int i = 0; i < pixelHeight / 12; i++) {
                memcpy(p, offset_U + start_uv + i*pixelWidth / 2, copyWidth_UV);
                p += copyWidth_UV;
            }

            //copy V 分量
            static uint8_t* offset_V = buf + pixelWidth*pixelHeight * 5 / 4;
            for (int i = 0; i < pixelHeight / 12; i++) {
                memcpy(p, offset_V + start_uv + i*pixelWidth / 2, copyWidth_UV);
                p += copyWidth_UV;
            }

            // 写入文件，生成脚本
            int writeSize = copyWidth*pixelHeight / 6 * 3 / 2;
            if (isfirsttimeopenfile[index]) {
                isfirsttimeopenfile[index] = false;
                fp[index] = fopen(outputfilename[index].c_str(), "wb");
                
                string bashcommand = "ffmpeg.exe -s " + to_string(copyWidth) +
                    "x" + to_string(pixelHeight / 6) + " -i " + outputfilename[index] +
                    " -s " + to_string(pixelWidth / 12) + "x" + to_string(pixelHeight / 6) +
                    " " + outputfilename[index].substr(0, outputfilename[index].find_last_of('_', 
                        outputfilename[index].find_last_of('_')-1) + 1) +
                    "downsampled_" + to_string(pixelHeight/6) + "x" + to_string(pixelHeight/6) + 
                    "_" + to_string(index) + ".yuv";
                fprintf(scriptfile, "%s\n", bashcommand.c_str());
            }
            fwrite(tmp_buffer, 1, writeSize, fp[index]);
        }
    }

    for (int i = 0; i < 42; i++) {
        fclose(fp[i]);
    }
    fclose(scriptfile);
    std::cout << "Finished!\n";
    return 0;
}