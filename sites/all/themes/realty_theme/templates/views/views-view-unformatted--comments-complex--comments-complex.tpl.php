<div class="col-xs-12 recall zero-padding">
  <?php if($comments):?>
    <?php foreach ($comments as $comment) :?>
      <h3>
        <?php print $comment['name'];?>
      </h3>
      <span>
     <?php print $image_finger;?>
   </span>
      <div class="date">
        <?php print $comment['date'];?>
      </div>
      <p>
        <?php print $comment['comment']?>
      </p>
    <?php endforeach;?>
  <?php endif;?>
</div>