[genrule(
    name = "count_lines_" + f,  # strip ".cc"
    srcs = [f],
    outs = ["%s-linecount.txt" % f],
    #cmd = "wc -l $< >$@",
    cmd = "cat $< > $@"
 ) for f in glob(["*_test.cc"])]
