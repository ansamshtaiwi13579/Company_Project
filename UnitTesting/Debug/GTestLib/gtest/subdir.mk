################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CC_SRCS += \
../GTestLib/gtest/gtest-all.cc 

CC_DEPS += \
./GTestLib/gtest/gtest-all.d 

OBJS += \
./GTestLib/gtest/gtest-all.o 


# Each subdirectory must supply rules for building sources it contributes
GTestLib/gtest/%.o: ../GTestLib/gtest/%.cc GTestLib/gtest/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -I"/home/user/eclipse-workspace/UnitTesting/GTestLib" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-GTestLib-2f-gtest

clean-GTestLib-2f-gtest:
	-$(RM) ./GTestLib/gtest/gtest-all.d ./GTestLib/gtest/gtest-all.o

.PHONY: clean-GTestLib-2f-gtest

