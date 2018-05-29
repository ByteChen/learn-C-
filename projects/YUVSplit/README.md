## 功能

* 按照42tile的划分方式，将输入的YUV切割成42块并保存到文件中，同时生成一个batch脚本，可直接利用ffmpeg.exe将42个YUV块下采样到同样的分辨率。
* 命令行输入格式：YUVSplit.exe input_file_name.yuv width height