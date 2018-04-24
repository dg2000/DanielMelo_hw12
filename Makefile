jflsdl:
	c++ DM_advection.cpp -o advection
	./advection > advection.txt
	python DM_graph.py
