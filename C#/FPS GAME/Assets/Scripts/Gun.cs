using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Gun : MonoBehaviour
{
    public GameObject bullet;
    public AudioSource audioSourcePlayer;


    private void Start()
    {
        audioSourcePlayer = GetComponent<AudioSource>();
    }
    // Update is called once per frame
    void Update()
    {
       if(Input.GetMouseButtonDown(0))
        {
            audioSourcePlayer.Play();
            GameObject newBullet = objectpool.SharedInstance.getPooledObject();
            newBullet.transform.position = new Vector3(transform.position.x , transform.position.y, transform.position.z);
            newBullet.GetComponent<Rigidbody>().velocity = transform.up* 50;
            newBullet.SetActive(true);


            
        }
    }
}
