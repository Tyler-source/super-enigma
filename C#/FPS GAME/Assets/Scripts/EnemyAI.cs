using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.AI;
using UnityEngine.UIElements;

[RequireComponent(typeof(NavMeshAgent))]
public class EnemyAI : MonoBehaviour
{
    public GameObject badguy;
    protected NavMeshAgent enemy;
    protected StateEnum State;
    protected Target[] PotentialTargets;
    protected Target target;
    protected float NextState;
    


    private void Awake()
    {
        enemy = GetComponent<NavMeshAgent>();
        PotentialTargets = FindObjectsOfType<Target>();
        target = PotentialTargets[Random.Range(0, PotentialTargets.Length)];
        State = StateEnum.RUN;

    }

    private void OnTriggerEnter(Collider other)
    {
        Destroy(badguy);
    }
    void Update()
    {
        enemy.updatePosition = false;
        enemy.updateRotation = false;
        enemy.updateUpAxis = false;
        NextState -= Time.deltaTime;
       
       
        switch (State)
        {
            case StateEnum.RUN:
                if (enemy.desiredVelocity.magnitude < 0.1f)
                {
                    State = StateEnum.STAY;
                    NextState = Random.Range(3f, 7f);
                }
                
                break;
            case StateEnum.STAY:
                if(NextState < 0)
                {
                    State = StateEnum.RUN;
                    target = PotentialTargets[Random.Range(0, PotentialTargets.Length)];
                    enemy.SetDestination(target.transform.position);
                }
                break;

        }
        transform.position += enemy.desiredVelocity * Time.deltaTime;
    }

    //State references
    //RUN: AI moves to various targets around the map.
    //CHASE: Run towards player for 5 seconds or so , then go to another target.
    public enum StateEnum
    {
        RUN,
        STAY
    }
}
