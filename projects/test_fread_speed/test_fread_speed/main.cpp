/*
* Copyright 2018 ByteChen. All rights reserved.
*
* Licensed under the BSD 3-Clause License (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
*     https://opensource.org/licenses/BSD-3-Clause
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*/

// Usage: 测试硬盘读取一帧YUV的耗时。输入格式：filename width height 
#include <iostream>
#include <windows.h>

int main(int argc, char* argv[]) {
    if (argc != 4) {
        std::cout << "Usage: 测试硬盘读取一帧YUV的耗时。输入格式：filename width height." <<std::endl;
        return -1;
    }
    char* pszFileName = argv[1];
    FILE* fpYUVFile = fopen(pszFileName, "rb");
    if (fpYUVFile == NULL) {
        throw "Failed to open file!\n";
    }
    int iPixelWidth = atoi(argv[2]);
    int iPixelHeight = atoi(argv[3]);
    int iFrameSize = iPixelHeight * iPixelWidth * 3 / 2;
    uint8_t* pucBuffer = new uint8_t[iFrameSize];
    if (pucBuffer == NULL)
        throw "fail to malloc memory\n";

    int iFrameCount = 0;
    LARGE_INTEGER liStart, liEnd, liFrequency;
    double dFreadTime;
    QueryPerformanceFrequency(&liFrequency);
    int iReadCount;

    while (1) {
        QueryPerformanceCounter(&liStart);

        iReadCount = fread(pucBuffer, 1, iFrameSize, fpYUVFile);

        QueryPerformanceCounter(&liEnd);
        if (iReadCount <= 0) {  // 读到文件结束或出错，退出
            break;
        }
        dFreadTime = (liEnd.QuadPart - liStart.QuadPart)*1000.0f / liFrequency.QuadPart;
        std::cout << ++iFrameCount << " fread cost time: " << dFreadTime << std::endl;
    }
    return 0;
}