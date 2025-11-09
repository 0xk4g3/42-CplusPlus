#!/bin/bash

# Author: hbendjab
# RPN Calculator HARDCORE Test Suite
# Tests: Overflow, Underflow, Long expressions, Edge cases

RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
BLUE='\033[0;34m'
MAGENTA='\033[0;35m'
CYAN='\033[0;36m'
NC='\033[0m' # No Color

echo -e "${MAGENTA}========================================${NC}"
echo -e "${MAGENTA}   RPN HARDCORE Test Suite${NC}"
echo -e "${MAGENTA}   Author: hbendjab${NC}"
echo -e "${MAGENTA}   Extreme Edge Cases & Overflow Tests${NC}"
echo -e "${MAGENTA}========================================${NC}"
echo ""

# Counter for passed/failed tests
PASSED=0
FAILED=0

# Test function
run_test() {
    local test_num=$1
    local description=$2
    local input=$3
    local expected=$4
    
    echo -e "${YELLOW}Test $test_num: $description${NC}"
    echo -e "Input: ${BLUE}$input${NC}"
    
    if [ -z "$input" ]; then
        result=$(./RPN 2>&1)
    else
        result=$(./RPN "$input" 2>&1)
    fi
    
    echo -e "Output: $result"
    echo -e "Expected: $expected"
    
    if [[ "$result" == *"$expected"* ]] || [[ "$expected" == *"$result"* ]]; then
        echo -e "${GREEN}✓ PASSED${NC}\n"
        ((PASSED++))
    else
        echo -e "${RED}✗ FAILED${NC}\n"
        ((FAILED++))
    fi
}

echo -e "${GREEN}=== BASIC VALID TESTS ===${NC}\n"

run_test 1 "Simple addition" "3 4 +" "7"
run_test 2 "Simple subtraction" "3 4 -" "-1"
run_test 3 "Simple multiplication" "3 4 *" "12"
run_test 4 "Simple division" "8 4 /" "2"
run_test 5 "Subject example 1" "8 9 * 9 - 9 - 9 - 4 - 1 +" "42"
run_test 6 "Subject example 2" "7 7 * 7 -" "42"
run_test 7 "Subject example 3" "1 2 * 2 / 2 * 2 4 - +" "0"

echo -e "${CYAN}=== INTEGER OVERFLOW TESTS ===${NC}\n"

run_test 8 "Large multiplication 9*9*9*9" "9 9 * 9 * 9 *" "6561"
run_test 9 "Massive calculation 9*9*9*9*9" "9 9 * 9 * 9 * 9 *" "59049"
run_test 10 "Even larger 9*9*9*9*9*9" "9 9 * 9 * 9 * 9 * 9 *" "531441"
run_test 11 "Extreme 9^8" "9 9 * 9 * 9 * 9 * 9 * 9 * 9 *" "43046721"
run_test 12 "Near INT_MAX" "9 9 * 9 * 9 * 9 * 9 * 9 * 9 * 9 *" "387420489"
run_test 13 "Potential overflow 9^10" "9 9 * 9 * 9 * 9 * 9 * 9 * 9 * 9 * 9 *" "Error"
run_test 14 "Giant multiplication chain" "9 9 * 9 * 9 * 9 * 9 * 9 * 9 * 9 * 9 * 9 *" "Error"

echo -e "${CYAN}=== INTEGER UNDERFLOW TESTS ===${NC}\n"

run_test 15 "Large negative result" "1 9 - 9 * 9 * 9 *" "-5832"
run_test 16 "Massive negative" "0 9 - 9 * 9 * 9 * 9 *" "-59049"
run_test 17 "Extreme negative" "1 9 - 9 * 9 * 9 * 9 * 9 *" "-472392"
run_test 18 "Near INT_MIN" "0 9 - 9 * 9 * 9 * 9 * 9 * 9 * 9 *" "-387420489"
run_test 19 "Potential underflow" "0 9 - 9 * 9 * 9 * 9 * 9 * 9 * 9 * 9 * 9 *" "Error"

echo -e "${CYAN}=== DIVISION BY ZERO TESTS ===${NC}\n"

run_test 20 "Direct division by zero" "5 0 /" "Error"
run_test 21 "Computed zero divisor" "5 5 - 3 swap /" "Error"
run_test 22 "Zero from subtraction" "9 0 /" "Error"
run_test 23 "Zero from operations" "1 1 - 5 swap /" "Error"

echo -e "${CYAN}=== LONG EXPRESSION TESTS ===${NC}\n"

run_test 24 "10 operations" "1 2 + 3 + 4 + 5 + 6 + 7 + 8 + 9 +" "45"
run_test 25 "20 operations" "1 1 + 1 + 1 + 1 + 1 + 1 + 1 + 1 + 1 + 1 + 1 + 1 + 1 + 1 + 1 + 1 + 1 + 1 + 1 +" "20"
run_test 26 "Complex long chain" "9 8 + 7 + 6 + 5 + 4 + 3 + 2 + 1 +" "45"
run_test 27 "Mixed operations long" "9 8 * 7 - 6 + 5 * 4 - 3 + 2 * 1 +" "155"
run_test 28 "Very long expression" "1 2 + 3 * 4 + 5 * 6 + 7 * 8 + 9 * 1 + 2 * 3 + 4 *" "4620"

echo -e "${CYAN}=== EXTREME EDGE CASES ===${NC}\n"

run_test 29 "Maximum single digit squared" "9 9 *" "81"
run_test 30 "All 9s multiplication" "9 9 9 * *" "729"
run_test 31 "Alternating ops" "9 1 - 1 + 1 - 1 + 1 - 1 + 1 -" "8"
run_test 32 "Division chain" "8 2 / 2 /" "2"
run_test 33 "Zero propagation" "0 5 * 9 +" "9"
run_test 34 "Negative to positive" "1 9 - 0 swap -" "8"
run_test 35 "Multiple zeros" "0 0 + 0 + 0 +" "0"

echo -e "${RED}=== ERROR TESTS ===${NC}\n"

run_test 36 "No arguments" "" "Error"
run_test 37 "Parentheses" "(1 + 1)" "Error"
run_test 38 "Number 10" "10 5 +" "Error"
run_test 39 "Number 11" "11 2 *" "Error"
run_test 40 "Number 100" "100 2 +" "Error"
run_test 41 "Number -10" "-10 5 +" "Error"
run_test 42 "Number -15" "-15 3 *" "Error"
run_test 43 "Insufficient operands" "5 +" "Error"
run_test 44 "Only operator" "+" "Error"
run_test 45 "Too many operands" "1 2 3 +" "Error"
run_test 46 "Too many operands 2" "1 2 3 4 + +" "Error"
run_test 47 "Invalid token abc" "1 2 abc" "Error"
run_test 48 "Invalid token 3r5" "3r5 2 +" "Error"
run_test 49 "Invalid operator %" "1 2 %" "Error"
run_test 50 "Invalid operator ^" "2 3 ^" "Error"
run_test 51 "Letters only" "a b c" "Error"
run_test 52 "Decimal number" "3.5 2 +" "Error"
run_test 53 "Double decimal" "3.5.5 2 +" "Error"
run_test 54 "Scientific notation" "1e5 2 +" "Error"
run_test 55 "Hexadecimal" "0x5 2 +" "Error"

echo -e "${CYAN}=== WHITESPACE & FORMAT TESTS ===${NC}\n"

run_test 56 "Multiple spaces" "3  4   +" "7"
run_test 57 "Leading spaces" "   3 4 +" "7"
run_test 58 "Trailing spaces" "3 4 +   " "7"
run_test 59 "Tabs instead of spaces" "3	4	+" "7"
run_test 60 "Only spaces" "   " "Error"
run_test 61 "Empty string" "" "Error"

echo -e "${CYAN}=== MIXED SIGN TESTS ===${NC}\n"

run_test 62 "Negative input -5" "-5 3 +" "Error"
run_test 63 "Negative input -9" "-9 2 *" "Error"
run_test 64 "Positive sign +5" "+5 3 +" "Error"
run_test 65 "Multiple signs --5" "--5 2 +" "Error"
run_test 66 "Sign without digit -" "5 - 3" "Error"

echo -e "${CYAN}=== OPERATOR PLACEMENT TESTS ===${NC}\n"

run_test 67 "Operator first" "+ 1 2" "Error"
run_test 68 "Two operators" "- - 5" "Error"
run_test 69 "Three operators" "+ - * 5" "Error"
run_test 70 "Operator sandwich" "5 + - 3" "Error"

echo -e "${CYAN}=== SPECIAL CHARACTER TESTS ===${NC}\n"

run_test 71 "Comma" "1,2 3 +" "Error"
run_test 72 "Semicolon" "1;2 3 +" "Error"
run_test 73 "Underscore" "1_2 3 +" "Error"
run_test 74 "Hash" "1#2 3 +" "Error"
run_test 75 "At sign" "1@2 3 +" "Error"
run_test 76 "Dollar sign" "$5 3 +" "Error"
run_test 77 "Percent" "5 3 % +" "Error"
run_test 78 "Ampersand" "5 & 3" "Error"
run_test 79 "Exclamation" "5! 3 +" "Error"
run_test 80 "Question mark" "5? 3 +" "Error"

echo -e "${CYAN}=== BOUNDARY VALUE TESTS ===${NC}\n"

run_test 81 "Exactly 9" "9 1 +" "10"
run_test 82 "Exactly -9" "0 9 -" "-9"
run_test 83 "Result exactly 10" "5 2 *" "10"
run_test 84 "Result exactly 0" "5 5 -" "0"
run_test 85 "Result exactly -1" "0 1 -" "-1"
run_test 86 "Division result 1" "5 5 /" "1"
run_test 87 "Division result 0" "0 5 /" "0"

echo -e "${CYAN}=== COMPLEX CALCULATION TESTS ===${NC}\n"

run_test 88 "Fibonacci-like" "1 1 + 2 + 3 + 5 +" "12"
run_test 89 "Factorial-like" "1 2 * 3 * 4 *" "24"
run_test 90 "Power-like 2^3" "2 2 * 2 *" "8"
run_test 91 "Power-like 3^3" "3 3 * 3 *" "27"
run_test 92 "Nested operations" "9 8 7 * + 6 -" "59"
run_test 93 "Reverse nested" "9 8 + 7 6 + *" "221"
run_test 94 "Mixed all ops" "9 8 + 7 * 6 - 5 / 4 + 3 - 2 * 1 +" "47"

echo -e "${CYAN}=== STRESS TESTS ===${NC}\n"

run_test 95 "50 additions" "1 1 + 1 + 1 + 1 + 1 + 1 + 1 + 1 + 1 + 1 + 1 + 1 + 1 + 1 + 1 + 1 + 1 + 1 + 1 + 1 + 1 + 1 + 1 + 1 + 1 + 1 + 1 + 1 + 1 + 1 + 1 + 1 + 1 + 1 + 1 + 1 + 1 + 1 + 1 + 1 + 1 + 1 + 1 + 1 + 1 + 1 + 1 + 1 + 1 +" "50"
run_test 96 "Alternating + and -" "9 1 + 1 - 1 + 1 - 1 + 1 - 1 + 1 - 1 + 1 -" "9"
run_test 97 "All multiplications" "2 2 * 2 * 2 * 2 * 2 *" "64"
run_test 98 "All divisions" "8 2 / 2 / 2 /" "1"
run_test 99 "Random complex" "9 7 * 5 + 3 - 2 / 4 *" "124"
run_test 100 "Final boss" "9 9 9 9 9 * * * *" "59049"

echo -e "${MAGENTA}========================================${NC}"
echo -e "${GREEN}PASSED: $PASSED${NC}"
echo -e "${RED}FAILED: $FAILED${NC}"
echo -e "${BLUE}TOTAL:  $((PASSED + FAILED))${NC}"
echo -e "${MAGENTA}========================================${NC}"

PERCENTAGE=$((PASSED * 100 / (PASSED + FAILED)))

if [ $FAILED -eq 0 ]; then
    echo -e "${GREEN}🎉🎉🎉 PERFECT SCORE! ALL 100 TESTS PASSED! 🎉🎉🎉${NC}"
elif [ $PERCENTAGE -ge 90 ]; then
    echo -e "${GREEN}🎉 EXCELLENT! $PERCENTAGE% PASSED! 🎉${NC}"
elif [ $PERCENTAGE -ge 75 ]; then
    echo -e "${YELLOW}👍 GOOD! $PERCENTAGE% PASSED! 👍${NC}"
elif [ $PERCENTAGE -ge 50 ]; then
    echo -e "${YELLOW}⚠️  NEEDS WORK! $PERCENTAGE% PASSED ⚠️${NC}"
else
    echo -e "${RED}❌ FAILED! Only $PERCENTAGE% PASSED ❌${NC}"
fi

echo -e "${MAGENTA}========================================${NC}"
