Different styles of writing networking (not only) code: https://stackoverflow.com/a/31298006/767632
Actually, any code with two participants, e.g. your program and the networking library.

Typically APIs only support one style, sometimes all.

# Blocking
You call a function, it does something and returns the result.
May _block_ your thread for a while or indefinitely.
Sometimes you may ask it to do multiple things and/or not block more than _a timeout_.

```
x = s.readInt();
cout << "Read: " << x;

if (s.readInt(y, 100ms)) {
    cout << "Read: " << y;
} else {
    cout << "Timed out\n";
}
```

Easier to code, impossible to interrupt, needs a thread per action.

# Callbacks
Also called: ~non-blocking, ~event-based, ~asynchronous.

You ask the library to do something, it starts doing in the background.
Your code proceeds.
It "calls you back" when it's done or failed.
You can take the next action then.

The library decides everything: when to call and what to do next.
You don't have "the next statement".

Much harder to code, easy to intermix and interrupt, only a single thread is needed (but there may be more).

## In frameworks
```
class MySocketHandler : public SocketHandler {
    void onConnected() override {
        this->startReadingInt();
        cout << "Started reading int\n";
    }

    void intRead(int x) override {
        cout << "Read: " << x << "\n";
        if (x % 2 == 0) {
            this->startReadingInt();
        } else {
            this->shutdown();
        }
    }
};
```

In Qt you have to manually connect signals with slots.

## In libraries
```
int main() {
    s1.startReadingInt([&](int x) {
        cout << "Read from s1: " << x;
        s1.startReadingInt([&](int y) {
            cout << "Read from s1: " << x << " " << y;
        });
    });
    s2.startReadingInt([](int x) {
        cout << "Read from s2: " << x;
    });
    // ...
    framework.run();
}
```

## Unanswered questions
* What thread do lambda/callback runs in?
  Typically there is a single dedicated "event thread" or "UI thread" which handles all events (including mouse and keyboard), you should never do anything long there.
* What mutexes are held? What operations are permitted?
* Can the callback run before `startReadingInt` returns?

# Polling
Also called: ~non-blocking, ~event-based, ~synchronous

Almost never happens in frameworks, they use it under the hood.
See `select` and `epoll` in Linux, `WaitForMultipleObjects` in Windows.
