#!/bin/bash

TMP=/tmp
FILEBASE=markov
FILEEXT=tex
FILECOMP=pdf
STYLEFILEBASE=markov

FILE=${FILEBASE}.$FILEEXT
FILEp=${FILEBASE}p.$FILEEXT
FILEpc=${FILEBASE}p.$FILECOMP
FILEt=${FILEBASE}-2.$FILEEXT
FILEtc=${FILEBASE}-2.$FILECOMP
FILEf=${FILEBASE}-4.$FILEEXT

sed \
    -e "s:\\\usepackage{$STYLEFILEBASE-color}:\\\usepackage{$STYLEFILEBASE-nocolor}:" \
    $FILE > $FILEp

pdflatex $FILE
pdflatex $FILE
pdflatex $FILEp
pdflatex $FILEp

cat > $FILEt << EOF
\documentclass[a4paper]{article}
\usepackage{pdfpages}
\begin{document}
\includepdf[
pages=-,
nup=1x2,
noautoscale,
trim=0 0 0 0,
delta=.5cm .5cm,
scale=1.4
]{$FILEpc}
\end{document}
EOF
pdflatex $FILEt

cat > $FILEf << EOF
\documentclass[a4paper]{article}
\usepackage{pdfpages}
\begin{document}
\includepdf[
pages=-,
nup=1x2,
trim=0 0 0 0,
delta=.5cm .5cm,
angle=-90,
]{$FILEtc}
\end{document}
EOF
pdflatex $FILEf
