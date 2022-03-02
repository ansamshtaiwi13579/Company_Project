################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
/home/user/eclipse-workspace/TrainingProject/src/Ceo.cpp \
/home/user/eclipse-workspace/TrainingProject/src/Company.cpp \
/home/user/eclipse-workspace/TrainingProject/src/Department.cpp \
/home/user/eclipse-workspace/TrainingProject/src/Employee.cpp 

CPP_DEPS += \
./src/Ceo.d \
./src/Company.d \
./src/Department.d \
./src/Employee.d 

OBJS += \
./src/Ceo.o \
./src/Company.o \
./src/Department.o \
./src/Employee.o 


# Each subdirectory must supply rules for building sources it contributes
src/Ceo.o: /home/user/eclipse-workspace/TrainingProject/src/Ceo.cpp src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -I"/home/user/eclipse-workspace/TrainingProject/includes" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/Company.o: /home/user/eclipse-workspace/TrainingProject/src/Company.cpp src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -I"/home/user/eclipse-workspace/TrainingProject/includes" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/Department.o: /home/user/eclipse-workspace/TrainingProject/src/Department.cpp src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -I"/home/user/eclipse-workspace/TrainingProject/includes" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/Employee.o: /home/user/eclipse-workspace/TrainingProject/src/Employee.cpp src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -I"/home/user/eclipse-workspace/TrainingProject/includes" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-src

clean-src:
	-$(RM) ./src/Ceo.d ./src/Ceo.o ./src/Company.d ./src/Company.o ./src/Department.d ./src/Department.o ./src/Employee.d ./src/Employee.o

.PHONY: clean-src

