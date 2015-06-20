LRTs
====

This is a port of https://github.com/jcc333/flc in c++
So far, it's a partial port of the underlying labeled-rooted-tree structures
Eventually (God willing), this will be more complete. I'd love to investigate storing 
these rules via a disk-backed queue and using an algorithm like Raft to agree
on state cross-machine. Since the decision procedure has a deterministic outcome,
and a reasonably low overhead, I'd be interested in seeing if some automated
reasoning could be distributed in a coherent way.
TODO:
  - support only the ground-literal Exclusion Logic terms
  - add support for deserialization with yacc
  - add support for forward-chain rules and conjunctions
  - add an expression type that handles variables,
    vectors and maps for inference purposes
  - conversions to/fro b+trees
