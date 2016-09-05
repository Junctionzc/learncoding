#!/bin/bash

repeat()
{
    while True
    do
        $@ && return
    done
}