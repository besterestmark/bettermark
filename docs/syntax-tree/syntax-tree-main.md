## This is the very work in progress syntax tree for bettermark

## Image

![image](https://user-images.githubusercontent.com/76597257/126086318-3e1f7742-f406-41c7-8914-bc3fec3e283a.png)

## Raw syntax

```
[BETTERMARK
  [ASTERISK
    [WHITESPACE
      [IDENTIFIER
        [EOL LIST-ASTERISK]
      ]
      [LBRACKET
        [x
          [RBRACKET
            [WHITESPACE
              [IDENTIFIER
                [EOL LIST-TASK-DONE-ASTERISK]
              ]
            ]
          ]
        ]
        [SLASH
          [RBRACKET
            [WHITESPACE
              [IDENTIFIER
                [EOL LIST-TASK-PROGRESS-ASTERISK]
              ]
            ]
          ]
        ]
        [HYPHEN
          [RBRACKET
            [WHITESPACE
              [IDENTIFIER
                [EOL LIST-TASK-DISABLED-ASTERISK]
              ]
            ]
          ]
        ]  
        [SPACE
          [RBRACKET
            [WHITESPACE
              [IDENTIFIER
                [EOL LIST-TASK-NOT-DONE-ASTERISK]
              ]
            ]
          ]
        ]
      ]
    ]
    [IDENTIFIER
      [ASTERISK ITALIC]
    ]
    [ASTERISK
      [IDENTIFIER
        [ASTERISK
          [ASTERISK BOLD]
        ]
      ]
    ]
    [OPEN-BRACKET
      [TERM
        [RBRACKET
          [COLON
            [WHITESPACE
              [IDENTIFIER ABBREVIATION]
            ]
          ]
        ]
      ]
    ]
  ]
  [HYPHEN
    [WHITESPACE
      [IDENTIFIER
        [EOL LIST-HYPHEN]
      ]
      [LBRACKET
        [x
          [RBRACKET
            [WHITESPACE
              [IDENTIFIER
                [EOL LIST-TASK-DONE-HYPHEN]
              ]
            ]
          ]
        ]
        [SLASH
          [RBRACKET
            [WHITESPACE
              [IDENTIFIER
                [EOL LIST-TASK-PROGRESS-HYPHEN]
              ]
            ]
          ]
        ]
        [HYPHEN
          [RBRACKET
            [WHITESPACE
              [IDENTIFIER
                [EOL LIST-TASK-DISABLED-HYPHEN]
              ]
            ]
          ]
        ]  
        [SPACE
          [RBRACKET
            [WHITESPACE
              [IDENTIFIER
                [EOL LIST-TASK-NOT-DONE-HYPHEN]
              ]
            ]
          ]
        ]
      ]
    ]
    [HYPHEN
      [HYPHEN
        [EOL HR-DEFAULT]
        [WHITESPACE
          [IDENTIFIER
            [WHITESPACE
              [HYPHEN
                [HYPHEN
                  [HYPHEN
                    [EOL HR-WORDS]
                  ]
                ]
              ]
            ]
          ]
        ]
      ]
    ]
  ]
  [TILDE
    [IDENTIFIER 
      [TILDE SUBSCRIPT]
    ]
    [TILDE 
      [IDENTIFIER
        [TILDE
          [TILDE STRIKETHROUGH]
        ]
      ]
    ]
  ]
  [UNDERSCORE
    [IDENTIFIER
      [UNDERSCORE UNDERLINE]
    ]
  ]
  [BANG
    [BANG
      [IDENTIFIER
        [BANG
          [BANG SPOILER]
        ]
      ]
    ]
    [LBRACKET
      [IDENTIFIER(ALT)
        [RBRACKET
        [LPAREN
          [IDENTIFIER(LINK)
            [RPAREN IMG-ALT]
              [WHITESPACE
                [IDENTIFIER(TITLE)
                  [RPAREN IMG-ALT-TITLE]
                  [WHITESPACE
                    [IDENTIFIER(SIZE)
                      [RPAREN IMG-ALT-TITLE-SIZE]
                    ]
                    [IDENTIFIER(ONCLICK.LINK)
                      [RPAREN IMG-ALT-TITLE-LINK]
                      [WHITESPACE
                        [IDENTIFIER(SIZE)
                          [RPAREN IMG-ALT-TITLE-LINK-SIZE]
                        ]
                      ]
                    ]
                  ]
                ]
                [IDENTIFIER(ONCLICK.LINK)
                  [RPAREN IMG-LINK]
                  [IDENTIFIER(SIZE)
                    [RPAREN IMG-LINK-SIZE]
                  ]
                ]
              ]
            ]
          ]
        ]
      ]
      [RBRACKET
        [LPAREN
          [IDENTIFIER(LINK)
            [RPAREN IMG]
            [WHITESPACE
              [IDENTIFIER(TITLE)
                [RPAREN IMG-TITLE]
                [WHITESPACE
                  [IDENTIFIER(SIZE)
                    [RPAREN IMG-TITLE-SIZE]
                  ]
                  [IDENTIFIER(ONCLICK.LINK)
                    [RPAREN IMG-TITLE-LINK]
                    [WHITESPACE
                      [IDENTIFIER(SIZE)
                        [RPAREN IMG-TITLE-LINK-SIZE]
                      ]
                    ]
                  ]
                ]
              ]
              [IDENTIFIER(ONCLICK.LINK)
                [RPAREN IMG-LINK]
                [IDENTIFIER(SIZE)
                  [RPAREN IMG-LINK-SIZE]
                ]
              ]
            ]
          ]
        ]
      ]
    ]
  ]
]
```
