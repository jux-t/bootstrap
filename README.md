# Arua Bootstrap Grammar/Parser

This repository houses the first iteration of the Arua Grammar.

It serves as a loose adaptation of what will be the Arua standard syntax, and may even
be a subset of it.

The goal of this repository is to convey the intended syntax of Arua and to create a
foundation on which the tooling can read Arua code.

## Approach

This parser uses a dialect of PEG called LEG, which is a slightly modified version of
Ford's original PEG syntax to accomodate for readability as well as the introduction of
a few yacc/flex features.

The expression parser fires off _basic_ events and is almost reverse-stack driven,
emitting events for prefix and postfix modification of terms until an AST can be built up.

For example, take the following complex type. The AST subsystem can easily figure out
what to 'pop' off the stack given the events emitted (shown in order, from top to bottom, left to right) -
with a reconstruction of the type step-by-step on the right:

```
type T<A, B<[C], D>, [[E<[F]>]]>
│    └─┼──┼──┼┼──┼─────┼──┼┼┼┼┼┼─ T <path end>                                                T
│      └──┼──┼┼──┼─────┼──┼┼┼┼┼┼─ A <path end> <type end>                                     T<A,>
│         └──┼┼──┼─────┼──┼┼┼┼┼┼─ B <path end>                                                T<A, B,>
│            └┼──┼─────┼──┼┼┼┼┼┼─ C <path end> <type end>                                     T<A, B<C>,>
│             └──┼─────┼──┼┼┼┼┼┼─ <array modifier>                                            T<A, B<[C],>,>
│                └─────┼──┼┼┼┼┼┼─ D <path end> <type end> <generic type end> <type end>       T<A, B<[C], D>,>
│                      └──┼┼┼┼┼┼─ E <path end>                                                T<A, B<[C], D>, E,>
│                         └┼┼┼┼┼─ F <path end> <type end>                                     T<A, B<[C], D>, E<F,>,>
│                          └┼┼┼┼─ <array modifier>                                            T<A, B<[C], D>, E<[F],>,>
│                           └┼┼┼─ <generic type end>                                          T<A, B<[C], D>, E<[F]>,>
│                            └┼┼─ <array modifier>                                            T<A, B<[C], D>, [E<[F]>],>
│                             └┼─ <array modifier>                                            T<A, B<[C], D>, [[E<[F]>]],>
│                              └─ <generic type end> <type end>                               T<A, B<[C], D>, [[E<[F]>]]>
└──────────────────────────────── type statement                                              type T<A, B<[C], D>, [[E<[F]>]]>
```

# License
MIT
