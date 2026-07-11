#!/bin/bash

usage() {
    echo "Usage: $0 LEVEL" >&2
}

password() {
    local level_number=$1

    if [ "$level_number" -le 0 ]; then
        echo "level00"
    else
        local prev_level_number=$(bc <<< "$level_number - 1")
        local prev_level=$(printf "level%02d" "$prev_level_number")
        if [ ! -f "$prev_level/flag" ]; then
            echo "Flag for level $prev_level_number not found" >&2
            return 1
        fi

        cat "$prev_level/flag"
    fi

    return 0
}

main() {
    if [ $# -ne 1 ]; then
        usage
        return 1
    fi

    local level_number
    level_number=$(tr -cd '0-9' <<< "$1")
    if [ -z "$level_number" ]; then
        echo "Invalid level: $level_number" >&2
        usage
        return 1
    fi

    local password
    password=$(password "$level_number")
    if [ $? -ne 0 ]; then
        return 1
    fi

    TERM=xterm-256color sshpass -p "$password" ssh -o LogLevel=ERROR "level$level_number@localhost" -p 4242
}

if [[ "${BASH_SOURCE[0]}" == "$0" ]]; then
    main "$@"
    exit $?
fi