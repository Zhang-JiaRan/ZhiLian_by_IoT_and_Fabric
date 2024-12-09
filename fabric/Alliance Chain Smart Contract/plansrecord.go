package main

import (
	"encoding/json"
	"fmt"

	"github.com/hyperledger/fabric-contract-api-go/contractapi"
)

// 定义可以实现上链以及读取的函数
type SmartContract struct {
	contractapi.Contract
}

// 定义变量
type Plan struct {
	Record      string `json:"Record"`
	Driver      string `json:"Driver"`
	Car         string `json:"Car"`
	ArrivalTime string `json:"ArrivalTime"`
	Phone       string `json:"Phone"`
	Address     string `json:"Address"`
}

// 初始化一个变量组，作为测试
func (s *SmartContract) InitLedger(ctx contractapi.TransactionContextInterface) error {
	plans := []Plan{
		{Record: "0", Driver: "李四", Car: "鲁E82980", ArrivalTime: "2023.03.13", Phone: "17856765456", Address: "山东省山东市山东县山东村"},
	}

	for _, plan := range plans {
		planJSON, err := json.Marshal(plan)
		if err != nil {
			return err
		}

		err = ctx.GetStub().PutState(plan.Record, planJSON)
		if err != nil {
			return fmt.Errorf("failed to put to world state. %v", err)
		}
	}

	return nil
}

// 新增加一个规划记录到链上
func (s *SmartContract) CreatePlan(ctx contractapi.TransactionContextInterface, record string, driver string, car string, arrivaltime string, phone string, address string) error {
	exists, err := s.PlanExists(ctx, record)
	if err != nil {
		return err
	}
	if exists {
		return fmt.Errorf("此规划 %s 已被记录过", record)
	}

	plan := Plan{
		Record:      record,
		Driver:      driver,
		Car:         car,
		ArrivalTime: arrivaltime,
		Phone:       phone,
		Address:     address,
	}
	planJSON, err := json.Marshal(plan)
	if err != nil {
		return err
	}

	return ctx.GetStub().PutState(record, planJSON)
}

// 用Record把记录的规划完全读取出来
func (s *SmartContract) ReadPlan(ctx contractapi.TransactionContextInterface, record string) (*Plan, error) {
	planJSON, err := ctx.GetStub().GetState(record)
	if err != nil {
		return nil, fmt.Errorf("读取失败： %v", err)
	}
	if planJSON == nil {
		return nil, fmt.Errorf("记录号为 %s 的规划不存在", record)
	}

	var plan Plan
	err = json.Unmarshal(planJSON, &plan)
	if err != nil {
		return nil, err
	}

	return &plan, nil
}

// 粗略查询是否存在记录
func (s *SmartContract) PlanExists(ctx contractapi.TransactionContextInterface, record string) (bool, error) {
	planJSON, err := ctx.GetStub().GetState(record)
	if err != nil {
		return false, fmt.Errorf("读取失败: %v", err)
	}

	return planJSON != nil, nil
}
