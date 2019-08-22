TestFixture_Sources = FileUtil.cpp Hex.cpp Parsing.cpp ResultParser.cpp stdafx.cpp Test.cpp TestFixture.cpp TestParser.cpp
TestFixture_Headers = FileUtil.h Hex.h Parsing.h RAII_Wrapper.h ResultParser.h stdafx.h Test.h TestParser.h
TestFixture_Deps = $(TestFixture_Sources) $(TestFixture_Headers)

TestFixture: $(TestFixture_Deps)
	g++ $(TestFixture_Sources) -o TestFixture -Os -flto
