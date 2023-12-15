<div align="center">
  <h1>Simple Shell</h1>
</div>

## Description

The Shell is a command-line interface that serves as a crucial bridge between users and the operating system. It provides a text-based environment where users can interact with the system by entering commands.


## Compilation

To compile the program this command has to be executed:
```
(&-) gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o a.out
```
To run the shell is like this:
```
(&-) ./a.out
```

## Usage

You can use these examples:

|- ls        | It is used to list the files and directories in a specified directory  |
| :--------- | ------------------------------------:                                  |
|- cd        | change the current working directory                                   |
|- pwd       | prints the full path of the current directory to the terminal          |
|- cat       | show you what we wrote in our file                                     |
|- env       | displays or modifies environment variables                             |
|- printenv  | displays all or specific environment variable values.                  |
|- exit      | shell will end and it gonna exit                                       |

## List of Functions

|- execute_command   | Execute a command                                       |
| :--------- | ------------------------------------:                           |
|- free_tokens       |  Free memory allocated for an array of strings          |
|- get_command       |  Resolves the full path of a command                    |
|- get_environment   |    Retrieves the value of an environment variable       |
|- tokenizer         |  Splits a string into an array of tokens.               |
|- shell             |   Entry point of the program                            |

## Authors

* Ismael Buere <a href="https://github.com/IsmaelBuere" rel="nofollow"><img align="center" alt="github" src="https://www.vectorlogo.zone/logos/github/github-tile.svg" height="24" /></a>
* Eithan Tabarez <a href="https://github.com/Eithan-Tabarez" rel="nofollow"><img align="center" alt="github" src="https://www.vectorlogo.zone/logos/github/github-tile.svg" height="24" /></a>
<br>
