################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../tests/AllTests.cpp 

CPP_DEPS += \
./tests/AllTests.d 

OBJS += \
./tests/AllTests.o 


# Each subdirectory must supply rules for building sources it contributes
tests/%.o: ../tests/%.cpp tests/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -I"/home/user/eclipse-workspace/TrainingProject/src" -I"/home/user/eclipse-workspace/TrainingProject/includes" -I"/home/user/eclipse-workspace/UnitTest/TestHeader" -I"/home/user/eclipse-workspace/UnitTesting/GTestLib" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-tests

clean-tests:
	-$(RM) ./tests/AllTests.d ./tests/AllTests.o

.PHONY: clean-tests

