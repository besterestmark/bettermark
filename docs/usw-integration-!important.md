Things that we need to cover in basedmark for [userstyle.world](https://userstyle.world) integration: 

Current parser used: https://github.com/russross/blackfriday (GOLANG)

---

OG: Intra-word emphasis supression. The _ character is commonly used inside words when discussing code, so having markdown interpret it as an emphasis command is usually the wrong thing. Blackfriday lets you treat all emphasis markers as normal characters when they occur inside a word.

Situation: We don't support `_italic_` either, BUT it's used for underline.

Fix: Make it so it won't match if there's non whitespace characters around it

Availability: yes, BUT with regex

---

OG: Tables. Tables can be created by drawing them in the input using a simple syntax:

Situation: We don't support tables yet, low on priority list due to difficulty. Likely have to use regex for them (bad).

Fix: Find a way to do them with regex somehow, or turn on regex only if beginning table syntax is recognized.

Availability: no, probably not soon due to difficulty

---

OG: Fenced code blocks. In addition to the normal 4-space indentation to mark code blocks, you can explicitly mark them and supply a language (to make syntax highlighting simple). Just mark it like this:

Situation: Supported, with highlight.js for syntax highlight which is also customisable

Fix: not needed :sunglasses: :fire: :100:!

Availability: yes!

---

OG: Definition lists. A simple definition list is made of a single-line term followed by a colon and the definition for that term.

Situation: Wasn't planned to be supported due to lack of usage but will be.

Fix: add to todo.md and specs.md before cpp gets done

Availability: no, wasn't planned to be added

---

OG: Footnotes. A marker in the text that will become a superscript number; a footnote definition that will be placed in a list of footnotes at the end of the document.

Situation: Planned to be implemented, unclear exactly how to do so.

Fix: Possibly by adding ids to the elements referenced

Availability: no, unclear how to implement.

---

OG: Strikethrough. Use two tildes (~~) to mark text that should be crossed out.

Situation: supported

Fix: not needed :sunglasses: :fire: :100:

Availability: yes

---

OG: Hard line breaks. With this extension enabled (it is off by default in the MarkdownBasic and MarkdownCommon convenience functions), newlines in the input translate into line breaks in the output.

Situation: Planned to be supported if not already supported (?)

Fix: add it to todo.md and specs.md then cpp parser

Availability: no, soon will be if it's not already (?)

---

OG: Smart quotes. Smartypants-style punctuation substitution is supported, turning normal double- and single-quote marks into curly quotes, etc.

Situation: Not planned to be supported, looks incredibly ugly and bad if users apply a custom font (usW users likely will). Also annoying for copying/pasting stuff. Also could interfere with code related things (`* { font-family: "Fira Code"; }` for example)

Fix: probablywontfixmaybeunlessneeded

Availabiltiy: no, probably not going to be supported unless really needed.

---

OG: LaTeX-style dash parsing is an additional option, where -- is translated into &ndash;, and --- is translated into &mdash;. This differs from most smartypants processors, which turn a single hyphen into an ndash and a double hyphen into an mdash.

Situation: Seems unneccesary, `---` is used for horizontal rules.

Fix: not planned to be supported

Availability: no, probably not goign to be added as it breaks other, more important syntax.

---

OG: Smart fractions, where anything that looks like a fraction is translated into suitable HTML (instead of just a few special cases like most smartypant processors). For example, 4/5 becomes <sup>4</sup>&frasl;<sub>5</sub>, which renders as 4⁄5.

Situation: almost supported:tm:

Fix: Implement in parser

Availability: no, will be supported soon:tm:

---

## Things we are against supporting in main, have them as option otherwise

`_italic_` - used for underline syntax; can break in code; `*italic*` exists and is more popular

`__bold__` - `**bold**` exists and is more popular; doesn't follow `italic`

`***` - `---` exists and is more popular and logical; too similar to `*italic*` and `**bold**`

`Indentation based code block/syntax in general` - unreadable; hard to maintain; hard to implement without bugs

```md
Heading 1
=========

Heading 2
---------
```
- unreadable; more difficult to maintain; goes against alignment syntax

## Thing we need to do

```md
1) brackets
2) need  to
3) work too
```

make bmark cmark compliant :pensive:
