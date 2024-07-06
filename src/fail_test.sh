#!/bin/bash

function is_failed {
    if test -f failed.test; then
        return 1
    fi
}

is_failed
