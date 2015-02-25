#ifndef BUFFER_PAIRS_H
#define BUFFER_PAIRS_H

/**
 * Two pointers are maintained:
 *
 * 1. lexemeBegin: marks the beginning of the
 * current lexeme;
 *
 * 2. forward: scans ahead until a pattern match
 * is found. When this occurs, forward is set to
 * the char at its right end. After this,
 * lexemeBegin is set to the char immediately
 * after the lexeme just found.
 */

void scan (void * forward, void * process)
{
  switch (*forward++)
  {
    case EOF:
    if (forward is at end of first buffer) {
      reload second buffer;
      forward = beginning of second buffer;
    } else if (forward is at end of second buff) {
      reload first buffer;
      forward =  beginning of first buffer;
    } else {
      terminate lexical analysis
    }

    process(char);
  }
}

#endif
