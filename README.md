# changeFrame

实现CAN总线协议下的帧转换。

输入的帧的格式为：

![pic1.png](https://github.com/terrycch/changeFrame/raw/master/Assets/Image/pic1.png)

在转换帧的格式时候，传出的帧为标准的帧的格式

1，单帧

2，第一帧

3，连续帧

4，最后帧

转换完成的格式为：

![pic2.png](https://github.com/terrycch/changeFrame/raw/master/Assets/Image/pic2.png)

开发环境： vs2019



注意事项：

in.txt文件的默认路径是 D:\\git\\changeFrame\\testfile\\in.txt

out.txt文件的默认路径是 D:\\git\\changeFrame\\testfile\\out.txt

如需更改,需要自己手动在源代码中修改.