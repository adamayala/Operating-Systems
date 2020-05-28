#!/bin/bash
# test 2
test $(./blist <<< "b , a") = yes
