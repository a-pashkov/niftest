```
application:ensure_started(niftest).

release_handler:upgrade_app(niftest, "lib/niftest-1.0.2").

release_handler:downgrade_app(niftest, "lib/niftest-1.0.1").

niftest:hello().
```
