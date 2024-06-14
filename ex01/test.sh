#!/bin/bash

# - settings ---------------------------
# 実行ファイル名
readonly EXECUTABLE_FILE_NAME="a.out"

# --------------------------------------

readonly EXECUTABLE_DIR_PATH=$(dirname "$0")
readonly EXE="${EXECUTABLE_DIR_PATH}/${EXECUTABLE_FILE_NAME}"
readonly MAKEFILE_PATH="${EXECUTABLE_DIR_PATH}/Makefile"
readonly TEST_NAME="${EXECUTABLE_FILE_NAME} test"
readonly BLUE="\033[34m"
readonly GREEEN="\033[32m"
readonly RED="\033[31m"
readonly DEFAULT="\033[0m"
readonly OK=${GREEEN}OK${DEFAULT}
readonly KO=${RED}KO${DEFAULT}

g_test_cnt=0
g_test_passed=0
g_test_failed=0

function err {
	echo $* >&2
}

# - init ---------------------------
function init {
	printf "\ \ \ \ \ \ \ \ \ \ ${TEST_NAME} / / / / / / / / / /\n"
	if ! build; then
		err "failed to build"
		exit 1
	fi
}

# - build ---------------------------
function build {
	printf "|- - - - - - - - - - build - - - - - - - - - -|\n"
	make -f ${MAKEFILE_PATH} || return 1
	return 0
}

# - results ---------------------------
function print_result {
	printf "\n|- - - - - - - - - - results - - - - - - - - - -|\n"
	printf "${g_test_cnt} tests run\n"
	printf "${GREEEN}${g_test_passed}${DEFAULT} passed\n"
	printf "${RED}${g_test_failed}${DEFAULT} failed\n"
	if [ ${g_test_cnt} -eq ${g_test_passed} ]; then
		printf "${GREEEN}Congratulations!${DEFAULT}\n"
	fi
}

# - assert ---------------------------
function assert {
	local exec="${EXE} $1"
	local actual=$(${exec})
	local expect=$2

	printf "${g_test_cnt}."
	if [ "${actual}" == "${expect}" ]; then
		printf "${OK} "
		((g_test_passed++))
	else
		printf "${KO}\n"
		printf "${BLUE}$>${DEFAULT} ${exec}\n"
		printf "${BLUE}■expect${DEFAULT}[${expect}]\n"
		printf "${BLUE}■actual${DEFAULT}[${actual}]\n"
		((g_test_failed++))
	fi
	((g_test_cnt++))
}

# - run_test ---------------------------
function run_test {
	printf "|- - - - - - - - - - start - - - - - - - - - -|\n"
	# 追加形式: assert <actual> <expect>
	assert "" "- 0 ────────────────────
(constructor)ClapTrap ST_1 has been created!
(constructor)ScavTrap ST_1 has been created!
- 1 ────────────────────
ScavTrap ST_1 attacks target1, causing 20 points of damage!
- 2 ────────────────────
ClapTrap ST_1 takes 5 points of damage!
- 3 ────────────────────
ClapTrap ST_1 is repaired for 3 points!
- 4 ────────────────────
ScavTrap ST_1 is now in Gate keeper mode!
- 5 ────────────────────
(constructor)ClapTrap Copy constructor called
ClapTrap Copy assignment operator called
(constructor)ScavTrap Copy constructor called
ScavTrap Copy assignment operator called
ClapTrap Copy assignment operator called
- 6 ────────────────────
ScavTrap ST_1 is now in Gate keeper mode!
- 7 ────────────────────
(constructor)ClapTrap Default constructor called
(constructor)ScavTrap Default constructor called
- 8 ────────────────────
ScavTrap Copy assignment operator called
ClapTrap Copy assignment operator called
- 9 ────────────────────
ScavTrap ST_1 is now in Gate keeper mode!
- 10 ────────────────────
(destructor)ScavTrap ST_1 has been destroyed!
(destructor)ClapTrap ST_1 has been destroyed!
(destructor)ScavTrap ST_1 has been destroyed!
(destructor)ClapTrap ST_1 has been destroyed!
(destructor)ScavTrap ST_1 has been destroyed!
(destructor)ClapTrap ST_1 has been destroyed!"
}

# - main ---------------------------
function main {
	init
	run_test
	print_result
	if [ ${g_test_failed} -ne 0 ]; then
		return 1
	fi
	return 0
}

main "$@"
