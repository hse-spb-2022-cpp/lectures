Рассказ получается вывернут наизнанку: цель в итоге в `vector<unique_ptr<Foo>>`,
но наследование возникает только в самом конце и непонятно, что и зачем.
Особенно непонятно, зачем `unique_ptr<Foo>`, когда есть просто `Foo`.
