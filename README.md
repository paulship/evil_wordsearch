# The Evil Wordsearch Project
Generates an evil wordsearch with a limited character space.

## So what's going on here then?

The purpose of this project is to generate a grid of letters, much like a wordsearch, but intended to confuse the reader looking for a single word. The grid is populated using only letters from the target word, but the target word will not appear anywhere in the wordsearch, along any vertical, horizontal, or diagonal.

It is inspired from a "bugsearch" post I came across online somewhere, but was unable to find again. The challenge was to find the word "BUG" in a vexatious grid of letters like this (along with some appropriately glib comment about how well this emulates the experience of bug hunting in the software development industry):

```
UBGUUBUBUBGUUBUBGBBGBBUBGBUBBBUUUBGUUUBBGBGBGUUGGBUBGBBUUGBG
BUBGBBGGBBBBBGGUGBBGGBGGBBGGGGUGUGBUUBBGGBBGUGUGGBUBBBGUGGGU
UBBBBBBGBBGGGGUUGGGGGUGBBBBGGBGUGGGGGGGGBGBBGUGGBBGBGGGBUBBU
UGGGUGGBUUBGBBGGGUUBGBUBBBGBBBUUBGGGGUGUUBGGUGUUGGGBUBUUGBGB
BGBBBBBBUUBUUBUBGUGUUUGBGGGBGBUBGBBBGGUGUGGBUUUGGGGUUUUUUUBU
UUUBBBBGBBBUBGUUBUUUUBGGBBGGGGUUUBGBBBGBGUGGBGGGBBUUGBUUUUUB
UUBGBGGGGUGBBBGBUBGUUBBGUGUGGBUBGUGGBBGGGGGGGBUUBBGUUBUBUBBB
UGBGGGGGBUUGGGGUUUBUUGGBUUUBGBBGGBGGBGGBUUUGBGUUGGGUGBGBUUBB
UBGGGGBBUUUGUGBUUUGBGUGUUUBUBBGBUUUGGBGGGUGGUGBBBGUUUBBBBBBG
GGGGGBGGBUUGUUGBUUGGGGUUGBGBBGGBUUGUUUUGBGGGBGBGBBUUGGBBGGGU
BBGBBUBBUUGGUGGGGGGBBUUGGGGUGUUGBBGUGUGBGGGBGBGUUBUUGBGBBBGU
BBGGUUUUBGBBBGUGUGGBGUUUBGUUGUUGGGBBGBBUUGBGGUUUUUGBUUGBBUBU
GGGGUUUUUGUGGUGUUUGBBGUUBUUGUUUUBBUUBBUUUBBBGBUUGBUBUBUBUBBU
BGGUGGBGBBUUBGBUUGGGGGUBUUBGUUUGGBUUBBUUBBBGGBGBUUUUBBGGBUUU
GGGGGGGBBUUUGGBBGGGBBUUGBBBGUGGBGGBBBBBBUBGBGBGUGUUBBGGBBBBU
BBGBBGBGBUUBUBBUBGUGBUUUBGUGBGGGBBUBBGGUUGBUBBGUUUBGBUBGUGGB
UBGGBGGGBGUGGUUUUUGUGUUUGGBBGUGBUUBUBGBUBBGBGGUGUGGBGGUUBUBU
UUGGBBBGGUGBUUBUUGUGBGBBBUBBGGBUUUUUUBGUGGGBGGUUBGGGBUUGUUGU
UUBUBGGGBGBBGGUGBGUGBBBUBGUUGBUUUUUUUGBBBGUUGGGGBUBGBUUUBGUG
GBUUUGBUBGUUGGUGUUGGBBBUUUUBUBUUBGGBGBBGGBUUGBUUGUUGGUUUGBGG
```

The word "BUG" does appear in the above grid following traditional wordsearch rules, but only once, and is obfuscated since the entire grid is comprised only of letters that make up the word "BUG".

This program assists with creating similar wordsearches that you can use for your own nefarious purposes. Please note however, the output from this program will *not* contain your target word - you will need to add that yourself in a subsequent step (maybe one day I'll update this to randomly insert the word somewhere as an option).


