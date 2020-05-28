#!/bin/bash
# test 5
test $(./blist <<< "b , b a") = no
