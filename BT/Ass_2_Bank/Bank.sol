// SPDX-License-Identifier: MIT
pragma solidity >=0.8.0;

contract bank{

    mapping (address=>uint256) public user_balance;
    mapping (address=>bool) public is_user;



    function create_account()public  {

        require(is_user[msg.sender]==false,'USer already exists');
        is_user[msg.sender]=true;

    }

    function deposit()public  payable {

        require(is_user[msg.sender],'User not exists');
        user_balance[msg.sender]+=msg.value;

    }

    function withdraw(uint256 amount)public {

        require(is_user[msg.sender],'User not exits');
        require(user_balance[msg.sender]>=amount,'Not much amount to be withdraw');
        require(payable(msg.sender).send(amount));
        user_balance[msg.sender]-=amount;
        
    }

    function show_balance(address user) public view  returns( uint256){
         require(is_user[msg.sender],'User not exits');
         return user_balance[user];
    }

    function delete_user()public {

         require(is_user[msg.sender],'User not exits');

         is_user[msg.sender]=false;
         user_balance[msg.sender]=0;

    }

}