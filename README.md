<h1 align="center">Welcome to BetterMark!</h1>
<div align="center"><p>A <a href="https://en.wikipedia.org/wiki/Markdown">Markdown</a> CLI converter & flavour that aims to compete in speed with popular parsers like <a href="https://commonmark.org">CommonMark</a>, whilst supporting many more unique features.</p></div>

## General info

- Uses C++14, better supported version
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
- Double slash comments (Original Feature)

### Features soon to be supported

- All types of lists, including lettered and roman
- 4 types of task lists (not done, done, disabled and in progress)
- Tables
- Custom HR with words in it
- And more, you can also leave your suggestions in the [issues section](https://github.com/besterestmark/bettermark/issues)!

## Speed comparison between Bmark and Cmark

Bettermark is faster than cmark and supports more features [stats coming soon].


<!--
|  Flavour   | Amount of features supported | test.md x 500 | test.md x 1 | 50mb x 500 | 50mb x 1 | Avg. Time/Feature |
| :--------: | :--------------------------: | :-----------: | :---------: | :--------: | :------: | :---------------: |
| BetterMark |          43/98               |       ?       |      ?      |     ?      |    ?     |         ?         |
| CommonMark |          ?/98                |       ?       |      ?      |     ?      |    ?     |         ?         |
-->

![image](https://user-images.githubusercontent.com/76597257/125636942-0602f191-2343-4cec-9f6a-bdbccc52a30b.png)


## Building/Installing

```bash
$ mkdir build
$ cd build
$ cmake ..
$ mv ./compile_commands.json ../ 
$ make
```

## Credits

- [highlight.js](https://highlightjs.org) for code block syntax highlighting

## Extra thanks to all these awesome contributors!

<a href="https://github.com/besterestmark/bettermark/graphs/contributors">
  <img src="https://contrib.rocks/image?repo=besterestmark/bettermark" />
</a>
