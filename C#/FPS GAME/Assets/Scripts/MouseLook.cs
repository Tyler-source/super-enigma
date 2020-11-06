using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.EventSystems;
using UnityEngine.UI;

public class MouseLook : MonoBehaviour
{
    //mouse sensitivity , multiplies the input from the mouse
    float mouseSensitivityY = 500f;
    float mouseSensitivityX = 500f;
    float xRotation = 0f;
    public Transform playerBody;
   

    void Start()
    {
        //remove cursor
        Cursor.lockState = CursorLockMode.Locked;
    }


    // Update is called once per frame
    void Update()
    {
        //gets a value to change the rotation of the camera
        float mouseX = Input.GetAxis("Mouse X") * mouseSensitivityX * Time.deltaTime;
        float mouseY = Input.GetAxis("Mouse Y") * mouseSensitivityY * Time.deltaTime;

        //Rotation
        playerBody.Rotate(Vector3.up * mouseX);
        xRotation -= mouseY;
        xRotation = Mathf.Clamp(xRotation,-90,90);
        transform.localRotation = Quaternion.Euler(xRotation,0f,0f);

        

    }
}
