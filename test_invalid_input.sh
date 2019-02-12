YELLOW='\033[0;33m'
NC='\033[0m' # No Color

printf "$YELLOW<== invalid input ==>$NC\n\n"

argc="./push_swap w"
printf "$argc\n"
$argc
printf "\n"

argc="./push_swap 12 34 -54 w 345 345"
printf "$argc\n"
$argc
printf "\n"

argc="./push_swap 12 -34 54 w34"
printf "$argc\n"
$argc
printf "\n"

argc="./push_swap 12- -34 54 23"
printf "$argc\n"
$argc
printf "\n"

argc="./push_swap 12 34 534-4 23"
printf "$argc\n"
$argc
printf "\n"

argc="./push_swap 12 -34 54 2147483647000"
printf "$argc\n"
$argc
printf "\n"

argc="./push_swap 12 -34 54 2147483649"
printf "$argc\n"
$argc
printf "\n"

argc="./push_swap 12 -34 54 2147483649"
printf "$argc\n"
$argc
printf "\n"

argc="./push_swap -2147483649"
printf "$argc\n"
$argc
printf "\n"

printf "$YELLOW<== correct input ==>$NC\n\n"

argc="./push_swap"
printf "$argc\n"
printf "Answer:\t\n"
$argc
printf "Expect:\t\n\n"

argc="./push_swap 2147483647"
printf "$argc\n"
printf "Answer:\t\n"
$argc
printf "Expect:\t\n\n"

argc="./push_swap -2147483648"
printf "$argc\n"
printf "Answer:\t\n"
$argc
printf "Expect:\t\n\n"

argc="./push_swap +123 -456"
printf "$argc\n"
$argc