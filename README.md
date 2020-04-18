# PYNQ-z2-opencv

该git记录了使用PYNQ实现OPENCV加速的整个过程，主要包括使用HLS编写核心算法，以及使用vivado实现覆盖。

第一部分为使用DMA实现的canny。

第二部分为使用DMA实现的resizer。

第三部分使用vdma实现sobel X+Y，实时性较佳。
