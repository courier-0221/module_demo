ASAN_CFLAGS := -fsanitize=address -fsanitize-recover=address
ASAN_CFLAGS += -fno-stack-protector -fno-omit-frame-pointer -fno-var-tracking
CPPFLAGS = -g -O2 -Wall -std=c++11

1_not_init_mem:
	g++ $(ASAN_CFLAGS) $(CPPFLAGS) -o 1_not_init_mem 1.not_init_mem.cc
run_1:
	export ASAN_OPTIONS=halt_on_error=0:use_sigaltstack=0:detect_leaks=1:malloc_context_size=15
	ASAN_OPTIONS=${ASAN_OPTIONS}:verbosity=0:handle_segv=1:allow_user_segv_handler=1:detect_stack_use_after_return=1:fast_unwind_on_fatal=1:fast_unwind_on_check=1:fast_unwind_on_malloc=1:quarantine_size=4194304
	./1_not_init_mem
clean_1:
	rm -rf 1_not_init_mem

2_mem_rw_over_limit:
	g++ $(ASAN_CFLAGS) $(CPPFLAGS) -o 2_mem_rw_over_limit 2.mem_rw_over_limit.cc
run_2:
	export ASAN_OPTIONS=halt_on_error=0:use_sigaltstack=0:detect_leaks=1:malloc_context_size=15
	ASAN_OPTIONS=${ASAN_OPTIONS}:verbosity=0:handle_segv=1:allow_user_segv_handler=1:detect_stack_use_after_return=1:fast_unwind_on_fatal=1:fast_unwind_on_check=1:fast_unwind_on_malloc=1:quarantine_size=4194304
	./2_mem_rw_over_limit
clean_2:
	rm -rf 2_mem_rw_over_limit

3_mem_leak:
	gcc $(ASAN_CFLAGS) -o 3_mem_leak 3.mem_leak.c
run_3:
	export ASAN_OPTIONS=halt_on_error=0:use_sigaltstack=0:detect_leaks=1:malloc_context_size=15
	ASAN_OPTIONS=${ASAN_OPTIONS}:verbosity=0:handle_segv=1:allow_user_segv_handler=1:detect_stack_use_after_return=1:fast_unwind_on_fatal=1:fast_unwind_on_check=1:fast_unwind_on_malloc=1:quarantine_size=4194304
	./3_mem_leak
clean_3:
	rm -rf 3_mem_leak

4_mem_coverage:
	gcc $(ASAN_CFLAGS) -o 4_mem_coverage 4.mem_coverage.c
run_4:
	export ASAN_OPTIONS=halt_on_error=0:use_sigaltstack=0:detect_leaks=1:malloc_context_size=15
	ASAN_OPTIONS=${ASAN_OPTIONS}:verbosity=0:handle_segv=1:allow_user_segv_handler=1:detect_stack_use_after_return=1:fast_unwind_on_fatal=1:fast_unwind_on_check=1:fast_unwind_on_malloc=1:quarantine_size=4194304
	./4_mem_coverage
clean_4:
	rm -rf 4_mem_coverage

5_dynamic_mem_manage:
	g++ $(ASAN_CFLAGS) $(CPPFLAGS) -o 5_dynamic_mem_manage 5.dynamic_mem_manage.cc
run_5:
	export ASAN_OPTIONS=halt_on_error=0:use_sigaltstack=0:detect_leaks=1:malloc_context_size=15
	ASAN_OPTIONS=${ASAN_OPTIONS}:verbosity=0:handle_segv=1:allow_user_segv_handler=1:detect_stack_use_after_return=1:fast_unwind_on_fatal=1:fast_unwind_on_check=1:fast_unwind_on_malloc=1:quarantine_size=4194304
	./5_dynamic_mem_manage
clean_5:
	rm -rf 5_dynamic_mem_manage

6_double_free:
	g++ $(ASAN_CFLAGS) $(CPPFLAGS) -o 6_double_free 6.double_free.cc
run_6:
	export ASAN_OPTIONS=halt_on_error=0:use_sigaltstack=0:detect_leaks=1:malloc_context_size=15
	ASAN_OPTIONS=${ASAN_OPTIONS}:verbosity=0:handle_segv=1:allow_user_segv_handler=1:detect_stack_use_after_return=1:fast_unwind_on_fatal=1:fast_unwind_on_check=1:fast_unwind_on_malloc=1:quarantine_size=4194304
	./6_double_free
clean_6:
	rm -rf 6_double_free

clean_all:clean_1 clean_2 clean_3 clean_4 clean_5 clean_6
	