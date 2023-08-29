# get_next_line

<p align="center">
  <img src="https://github.com/alissonmarcs/42-project-badges/blob/main/badges/get_next_linee.png" alt="get_next_line 42 project badge"/>
</p>
<p align="center">Grade: 112/100</p>

In  the second project of 42 School, we are asked to create a function that get next line of a file descriptor, prototyped as `char *get_next_line(int fd);`. The only allowed functions to implement this is `malloc()`, `free()` and `read()`. In the bonus part, `get_next_line()` must work propely with multiple file descriptors and it must be implemented using only one static variable.

## Challenges involved and how I solve them
The challenge is that `read()` function must read `BUFFER_SIZE` (macro defined in header) bytes per call of it, we are no allowed to read entire file to process it latter. If the `\n` is on middle of bytes readed, I return that `\n` and every content that preced it, and the content after it I store in a static variable, to return it in next call.

The mandatory part return a wrong line if we do a second call to `get_next_line()` with other file descriptor, because static variable have content of one file, that will be concatened with content of another file. I need a way to store a specific after new line content for your respective `fd`. I do this using static array were `fd` parameter will be index of that array.

## Mandatory part
| File | Description |
|------|-------------|
|[get_next_line.c](https://github.com/alissonmarcs/get_next_line/blob/main/get_next_line.c)|Main logic|
|[get_next_line_utils.c](https://github.com/alissonmarcs/get_next_line/blob/main/get_next_line_utils.c)|Helper functions|
|[get_next_line.h](https://github.com/alissonmarcs/get_next_line/blob/main/get_next_line.h)|Interface for helper functions|

## Bonus part
| File | Description |
|------|-------------|
|[get_next_line_bonus.c](https://github.com/alissonmarcs/get_next_line/blob/main/get_next_line_bonus.c)| Main logic |
|[get_next_line_utils_bonus.c](https://github.com/alissonmarcs/get_next_line/blob/main/get_next_line_utils_bonus.c)| Helper functions |
|[get_next_line_utils_bonus.h](https://github.com/alissonmarcs/get_next_line/blob/main/get_next_line_bonus.h)| Interface for helper functions |


## View it working
Take a look in examples directory, [mandatory/bonus].c have comments indicating how to complile them.

## Little note
The maximun grade is 125/100, but I get 112/100. This is because in my bonus files, my user name is deferent in 42 header, as I do its in my home :( (the lesson was learned). These files are the same as I send to the 42 intra.
