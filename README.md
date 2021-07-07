<h1 align="center">Welcome to BetterMark!</h1>
<div align="center"><p>A <a href="https://en.wikipedia.org/wiki/Markdown">Markdown</a> CLI parser & flavour that aims to compete in speed with popular parsers like <a href="https://commonmark.org">CommonMark</a>, whilst supporting many more unique features.</p></div>

## General info

- Uses C++14, a widely supported version of C++
- Faster than most JavaScript parsers
- Extremely extensible CSS-wise
  + Multiple already available themes like [Gruvbox](https://github.com/morhetz/gruvbox) and [Lantern-theme](https://github.com/Gitleptune/lantern-theme)
  + Ability to customise the CSS and add your own classes
  + Customisable syntax highlighting with [highlight.js](https://highlightjs.org)

## Features

Everything that has support or will be supported soon can be seen in [todo.md](https://github.com/besterestmark/bettermark/blob/master/docs/todo.md)

### Features currently supported

- Most of [Commonmark](https://commonmark.org)
- Custom Classes
- Heading-alignment (Original Feature)

### Features soon to be supported

- All types of lists, including lettered and roman
- 4 types of task lists (not done, done, disabled and in progress)
- Double slash comments Comments
- Tables
- Custom HR with words in it
- And more! You can also leave suggestions in the [issues](https://github.com/besterestmark/bettermark/issues)!

## Comparison between BetterMark and CommonMark

The benchmark file [test.md](https://github.com/besterestmark/bettermark/blob/master/docs/test.md) was parsed 500 times with both Bmark and Cmark, with Cmark coming on top by `4`s in total or `~125`ms per parse.

|  Flavour   | Amount of features supported | test.md x 500 | test.md x 1 | 50mb x 500 | 50mb x 1 | Avg. Time/Feature |
| :--------: | :--------------------------: | :-----------: | :---------: | :--------: | :------: | :---------------: |
| BetterMark |          29/98 (?)           |       ?       |      ?      |     ?      |    ?     |         ?         |
| CommonMark |             ?/98             |       ?       |      ?      |     ?      |    ?     |         ?         |


## Building/Installing

```bash
$ mkdir build
$ cd build
$ cmake ..
$ mv ./compile_commands.json ../ 
$ make
```
