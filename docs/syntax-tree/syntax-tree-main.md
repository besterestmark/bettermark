## This is the very work in progress syntax tree for bettermark

## Image

![image](https://user-images.githubusercontent.com/76597257/126051995-905ca7dd-dc9c-4296-9006-da83bf97fb5d.png)

## Raw syntax

```pain
[BETTERMARK
  [ASTERISK
    [WHITESPACE
      [IDENTIFIER
        [EOL LIST-ASTERISK]
      ]
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
				[CLOSE-BRACKET
					[WHITESPACE
						[IDENTIFIER
							[EOL LIST-TASK-PROGRESS-ASTERISK]
						]
					]
				]
			]
			[HYPHEN
				[CLOSE-BRACKET
					[WHITESPACE
						[IDENTIFIER
							[EOL LIST-TASK-DISABLED-ASTERISK]
						]
					]
				]
			]  
			[SPACE
				[CLOSE-BRACKET
					[WHITESPACE
						[IDENTIFIER
							[EOL LIST-TASK-NOT-DONE-ASTERISK]
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
        [CLOSE-BRACKET
          [COLON
            [WHITESPACE
              [IDENTIFIER ABBREVIATION]
            ]
          ]
        ]
      ]
    ]
  ]
]
```
