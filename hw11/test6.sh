#!/bin/bash
# test 6
test $(./blist <<< "b , b , a") = yes
