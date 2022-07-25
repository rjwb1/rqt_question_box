# rqt_question_box
Simple rosservice triggered question box for user intervention and queries

## Basic Usage 

Get "yes or no" dialog box with question "Foo Bar?"

```
rosservice call /rqt_question_box "question: 'Foo Bar?' type: 'bool'"
```

<p align="center">
  <img src="https://user-images.githubusercontent.com/66944854/180826532-2134d5c0-4eb1-405b-b43b-36ab073061b4.png"  width="350" height="300"/>
</p>

Get string entry dialog box with question "Foo Bar?"

```
rosservice call /rqt_question_box "question: 'Foo Bar?' type: 'string'"
```

<p align="center">
  <img src="https://user-images.githubusercontent.com/66944854/180827839-01b89411-bf0e-410c-997a-424e675e4c61.png"  width="350" height="300"/>
</p>

Calling the service multiple times is supported and dialog boxes will be generated sequentially and chronologically depending on the time the request was recieved.

##TODO 

- Add Keypad 'int' dialog box 
- Dynamic Namespace 
- Listen to topic and display on box
- Tidy up
