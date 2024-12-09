package main

import (
	"log"

	"github.com/hyperledger/fabric-contract-api-go/contractapi"
)

func main() {
	planChaincode, err := contractapi.NewChaincode(&SmartContract{})
	if err != nil {
		log.Panicf("部署智能合约失败: %v", err)
	}

	if err := planChaincode.Start(); err != nil {
		log.Panicf("智能合约启动失败: %v", err)
	}
}
