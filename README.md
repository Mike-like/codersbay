# CODERSBAY
codersbay is a (work in progress) esoteric programming language based on [Brainfuck](
https://en.wikipedia.org/wiki/Brainfuck).

| Key | Value                                                                                                                                                        |
| --- |--------------------------------------------------------------------------------------------------------------------------------------------------------------|
| Version | 0.0.1                                                                                                                                                        |
| Author | Michael Bockel (Mike-like)                                                                                                                                   |
| License | GNU General Public License (Version 3) https://www.gnu.org/licenses/gpl-3.0.en.html <br/>This license applies to the specification and not code written using it. |    

## Keywords

A "bay" Program is a space seperated sequence of the following Keywords. "/n", "/r", etc. are (currently) not allowed.

| Keyword    | Meaning                                                                                                                            |
|------------|------------------------------------------------------------------------------------------------------------------------------------|
| `mike`     | Increment the data pointer by 1.                                                                                                   |
| `patricia` | Decrement the data pointer by 1.                                                                                                   |
| `andi`     | Increment the value pointed to by the data pointer by 1.                                                                           |
| `hias`     | Decrement the value pointed to by the data pointer by 1.                                                                           |
| `franky`   | Write the value pointed to by the data pointer as character to the output (currently console).                                     |
| `stefan`   | Read a character from the input into the value pointed to by the data pointer (untested).                                          |
| `phil`     | If the value pointed to by the data pointer is zero, then continue execution of the program after the matching `oliver` keyword.   |
| `oliver`   | If the value pointed to by the data pointer is not zero, then continue execution of the program after the matching `phil` keyword. |

## CLI Options

| Option   | Meaning                                                               |
|----------|-----------------------------------------------------------------------|
| `--alex` | Verbose mode: Displays detailed information for each command executed |
