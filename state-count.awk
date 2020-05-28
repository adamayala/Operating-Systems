{
    state_cnt[$1]++
}
END {
      for (state in state_cnt) {
          print state, state_cnt[state]
      }
}
