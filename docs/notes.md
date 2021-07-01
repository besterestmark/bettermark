## HTML

- Have <title> tag for search engine optimization
- Have DOCTYPE
- No inline js or style
- option for minified everything (html, css and js if any)
  + option to not use the js libraries (if any)

## JS

- Load last to not slow down page (put at end of html)
- Minify and have as less files as possible
- Highlight.js for syntax highlighting (?)

## CSS

- Minify and have as less files as possible
- Have multiple stylesheets
  + Lantern (chad)
  + Gruvbox
  + others

## Ideas

- TOC
	+ TOC 1|2|3|4|5|6 for depth of headings shown (Default is TOC6 aka the most)
	+ Syntax maybe `[TOC(1|2|3|4|5|6)]`
  + cool https://github.com/3r3bu5x9/Prismatic-Night#table-of-contents
- TODOs
  + [ ] not done
	+ [x] done
	+ [/] in progress
  + [-] disabled
  + Support +/-/* for it as well
- `--- content ---` makes text be inside something like an hr

## Concerns

- Headings
  + match with whitespace before `    :# im an epic chad with a space` // FIXED

## Options

- SHORT_MODE
  + <blockquote> vs <q> (inline)
  + <strong> vs <b> (inlne)
  + <em> vs <i> (inline)
  + <span> vs <div> (FOR SPOILERS)

## TODO

- PRELUDE VARS
  + &DATE&
  + &MONTH&
  + &YEAR&

## Warnings

- Whitespace before heading
- No empty line around/after headings
- No space after blockquote [UNLESS ANOTHER BLOCKQUOTE]

