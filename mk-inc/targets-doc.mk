BIN_DOXYGEN     := doxygen
DIR_DOC_OUT     :=$(DIR_OUTPUT)/doc/



##  @brief  Target to build development documentation.
doc: doxygen	#help: build development documentation.



##  @brief  Target to generate Doxygen documentation.
doxygen: directories	#help: Target to generate Doxygen documentation.
	@echo -e "${lColorDoc}    DOC $@${CLREOL}${FMT_STD}" $(TRACE_LOG)
	@if [ ! "$(TRACES)" -eq "0" ] ; then \
		echo "$(BIN_DOXYGEN) $(DIR_DOC)/doxygen/doxygen.conf" $(TRACE_REDIRECT); \
	fi
	@$(BIN_DOXYGEN) $(DIR_DOC)/doxygen/doxygen.conf $(TRACE_REDIRECT)



##  @brief  Target to remove documentation only.
clean-doc:	#help: Target to remove documentation only.
	@echo -e "${lColorRM}    RM  ./$(DIR_DOC_OUT)/ ${CLREOL}$(FMT_STD)" #$(TRACE_REDIRECT);
	@$(RM) -rvf ./$(DIR_DOC_OUT)/ #$(TRACE_REDIRECT)



##  @brief  Convenience target to open the documentation main page.
open-docdev:	#help: Convenience target to open the documentation main page.
	@xdg-open $(DIR_DOC_OUT)/html/index.html
