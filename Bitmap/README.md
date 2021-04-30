# Bitmap

A bitmap is a bool array which allows you to access and modify individual bits. While usually the byte is the smallest accessible unit of memory,
with the help of bitwise operations we can obtain an 8 times more space efficient array of boolean values.

It is a data structure often used in the kernel, due to its space efficiency. An example of this would be disk drives. A **disk drive** may be
separated into several thousand **disk blocks**. A bitmap can be used to store the status(availability) of each of those blocks.
