"""Fake fake multiple dispatch"""

from itertools import product

class A:
    ...

class B:
    ...

class C:
    ...

class Rule:
    def __init__(self):
        self._rules = {
            (A, B): RuleAB,
            (A, object): RuleA,
            (object, B): RuleB,
            (object, object): RuleElse,
        }

    def match(self, a, b):
        args = product([type(a), type(b), object], repeat=2)
        for arg in args:
            try:
                lhs, rhs = arg
                return self._rules[(lhs, rhs)]()
            except KeyError:
                continue
        return Rule()

    def foo(self):
        raise NotImplementedError

class RuleAB(Rule):
    def foo(self):
        print("AB")

class RuleA(Rule):
    def foo(self):
        print("A")

class RuleB(Rule):
    def foo(self):
        print("B")

class RuleElse(Rule):
    def foo(self):
        print("Else")

Rule().match(A(), B()).foo()
Rule().match(A(), C()).foo()
Rule().match(C(), B()).foo()
Rule().match(C(), C()).foo()
