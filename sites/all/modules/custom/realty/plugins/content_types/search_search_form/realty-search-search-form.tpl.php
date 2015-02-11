
<div class="container-fluid container-fix issue-header" style="background-image: url(<?php if(!empty($image_path)): print $image_path; endif?>);">
  <div class="row relative">
    <div class="col-xs-4 parent issue-discription">
      <div class="col-xs-12 second-quarter-item second-quarter-item-issue  zero-padding item-text-field">
        <p>
          <?php print $description; ?>
        </p>
        <?php print $details;?>
      </div>
    </div>
  </div>
</div>

<div class="container fin">
  <div class="col-xs-12 zero-padding search-block-issue">
    <?php print render($search_form);?>
  </div>
</div>
<?php print $modal;?>