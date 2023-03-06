1_not_init_mem:
	g++ -g -o 1_not_init_mem 1.not_init_mem.cc
run_1:
	valgrind --tool=memcheck --leak-check=full ./1_not_init_mem 
clean_1:
	rm -rf 1_not_init_mem

2_mem_rw_over_limit:
	g++ -g -o 2_mem_rw_over_limit 2.mem_rw_over_limit.cc
run_2:
	valgrind --tool=memcheck --leak-check=full ./2_mem_rw_over_limit 
clean_2:
	rm -rf 2_mem_rw_over_limit

3_mem_leak:
	gcc -g -o 3_mem_leak 3.mem_leak.c
run_3:
	valgrind --tool=memcheck --leak-check=full ./3_mem_leak 
clean_3:
	rm -rf 3_mem_leak

4_mem_coverage:
	gcc -g -o 4_mem_coverage 4.mem_coverage.c
run_4:
	valgrind --tool=memcheck --leak-check=full ./4_mem_coverage 
clean_4:
	rm -rf 4_mem_coverage

5_dynamic_mem_manage:
	g++ -g -o 5_dynamic_mem_manage 5.dynamic_mem_manage.cc
run_5:
	valgrind --tool=memcheck --leak-check=full ./5_dynamic_mem_manage 
clean_5:
	rm -rf 5_dynamic_mem_manage

6_double_free:
	g++ -g -o 6_double_free 6.double_free.cc
run_6:
	valgrind --tool=memcheck --leak-check=full ./6_double_free 
clean_6:
	rm -rf 6_double_free