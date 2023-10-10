 /* 
  * Lexer for (dele af) Sok, "semantikopgavens konstruktion"
  * Uli Fahrenberg, 2007
  * This code is in the public domain
  */

%%

 /* reserverede ord */
end|kald|metode|var   printf( "Et reserveret ord: %s\n", yytext);

 /* L1 */
[a-zA-Z][a-zA-Z0-9]*  printf( "En variabel: %s\n", yytext);

 /* L2 */
[+-]?[1-9][0-9]*      printf( "Et heltal: %s\n", yytext);

=                     printf( "En initialisering\n");

:=                    printf( "En tilskrivning\n");

\(                    printf( "En åben parentes\n");

\)                    printf( "En lukket parentes\n");

[+*]                  printf( "En operation: %s\n", yytext);

%%

int main( int argc, char **argv) {
  if( argc> 1)
    yyin= fopen( argv[ 1], "r");
  else
    yyin= stdin;

  yylex();
}
